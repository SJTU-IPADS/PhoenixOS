/*
 * Copyright 2024 The PhoenixOS Authors. All rights reserved.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "autogen_common.h"


void POSCodeGen_CppBlock::archive(){
    uint64_t i;
    std::string line;

    auto __insert_tab = [&](uint16_t num){
        uint16_t k; for(k=0; k<num; k++){ this->archived += "\t"; }
    };

    auto __write_line = [&](std::string& line){
        this->archived += line + std::string("\n");
    };

    auto __write_line_without_change_line = [&](std::string& line){
        this->archived += line;
    };

    auto __insert_empty_line = [&](uint64_t num){
        uint64_t l;
        for(l=0; l<num; l++){ this->archived += std::string("\n"); }   
    };

    // block name
    if(this->_block_name.size() > 0){
        __insert_tab(this->_level);
        __write_line(this->_block_name);
    }

    // brace start
    if(this->_need_braces > 0){
        __insert_tab(this->_level);
        std::string l_brace("{");
        __write_line(l_brace);
    }

    // var declarations
    for(i=0; i<this->_vars.size(); i++){
        __insert_tab(this->_level+1);
        __write_line(this->_vars[i]);
    }
    if(this->_vars.size() > 0)
        __insert_empty_line(1);

    if(this->_contents.size() > 0){ 
        // this is a leaf block
        POS_ASSERT(this->_inner_blocks.size() == 0);
        for(i=0; i<this->_contents.size(); i++){
            // spliting contains based on '\n'
            std::stringstream ss(this->_contents[i]);
            while (std::getline(ss, line)) {
                __insert_tab(this->_level+1);
                __write_line(line);
            }
            __insert_empty_line(1);
        }
    } else {
        // this is a parent block, archive its leaves
        for(i=0; i<this->_inner_blocks.size(); i++){
            this->_inner_blocks[i]->archive();
            __write_line(this->_inner_blocks[i]->archived);
        }
    }

    // brace stop
    if(this->_need_braces > 0){
        __insert_tab(this->_level);
        if(this->_need_foot_comment){
            std::string r_brace = std::string("} // ") + this->_block_name;
            __write_line_without_change_line(r_brace);
        } else {
            std::string r_brace("}");
            __write_line_without_change_line(r_brace);
        }
    }

exit:
    ;
}


bool POSCodeGen_CppBlock::declare_var(std::string var){ 
    // avoid duplication
    for(std::string& _var : this->_vars){
        if(unlikely(_var == var)){ return true; }
    }
    this->_vars.push_back(var);
    return false;
}


void POSCodeGen_CppBlock::append_content(std::string content){
    POS_ASSERT(this->_inner_blocks.size() == 0);
    this->_contents.push_back(content);
}


pos_retval_t POSCodeGen_CppBlock::allocate_block(
    std::string block_name, POSCodeGen_CppBlock** new_block, bool need_braces, bool need_foot_comment, int level_offset
){
    pos_retval_t retval = POS_SUCCESS;
    uint8_t new_level;

    POS_CHECK_POINTER(new_block);

    if(level_offset < 0){
        POS_ASSERT(std::abs(level_offset) <= static_cast<int>(this->_level));
    }
    
    if(level_offset >= 0){
        new_level = static_cast<uint8_t>(level_offset) + this->_level;
    } else {
        new_level = this->_level - static_cast<uint8_t>(std::abs(level_offset));
    }
    
    *new_block = new POSCodeGen_CppBlock(block_name, need_braces, need_foot_comment, new_level);
    POS_CHECK_POINTER(*new_block);

    this->_inner_blocks.push_back(*new_block);
    
    return retval;
}


void POSCodeGen_CppSourceFile::add_include(std::string include){
    this->_includes.push_back(include);
}


void POSCodeGen_CppSourceFile::add_block(POSCodeGen_CppBlock* block){
    POS_CHECK_POINTER(block);
    this->_blocks.push_back(block);
}


void POSCodeGen_CppSourceFile::archive(){
    uint64_t i;

    auto __write_block = [&](std::string& block){
        this->archived += block + std::string("\n");
    };

    auto __insert_empty_line = [&](uint64_t num){
        uint64_t l;
        for(l=0; l<num; l++){ this->archived += std::string("\n"); }   
    };

    for(i=0; i<this->_includes.size(); i++){ __write_block(this->_includes[i]); }
    if(this->_includes.size() > 0)
        __insert_empty_line(1);

    for(i=0; i<this->_blocks.size(); i++){
        POS_CHECK_POINTER(this->_blocks[i]);
        this->_blocks[i]->archive();
        __write_block(this->_blocks[i]->archived);
    }

    this->_file_stream << this->archived;
    this->_file_stream.flush();
}
