#include "autogen_common.h"


void POSCodeGen_CppBlock::archive(){
    uint64_t i;

    auto __insert_tab = [&](uint16_t num){
        uint16_t k; for(k=0; k<num; k++){ this->archived += "\t"; }
    };

    auto __write_block = [&](std::string& block){
        this->archived += block + std::string("\n");
    };

    auto __insert_empty_line = [&](uint64_t num){
        uint64_t l;
        for(l=0; l<num; l++){ this->archived += std::string("\n"); }   
    };

    // block name
    if(this->_block_name.size() > 0){
        __insert_tab(this->_level);
        __write_block(this->_block_name);
    }

    // brace start
    if(this->_need_braces > 0){
        __insert_tab(this->_level);
        std::string l_brace("{");
        __write_block(l_brace);
    }

    // var declarations
    for(i=0; i<this->_vars.size(); i++){
        __insert_tab(this->_level+1);
        __write_block(this->_vars[i]);
    }
    __insert_empty_line(2);

    
    if(this->_contents.size() > 0){ 
        // this is a leaf block
        POS_ASSERT(this->_inner_blocks.size() == 0);
        for(i=0; i<this->_contents.size(); i++){
            __insert_tab(this->_level);
            __write_block(this->_contents[i]);
        }
    } else {
        for(i=0; i<this->_inner_blocks.size(); i++){
            this->_inner_blocks[i]->archive();
            __write_block(this->_inner_blocks[i]->archived);
            __insert_empty_line(1);
        }
    }

    // brace stop
    if(this->_need_braces > 0){
        __insert_tab(this->_level);
        std::string r_brace("}");
        __write_block(r_brace);
    }

exit:
    ;
}


void POSCodeGen_CppBlock::declare_var(std::string var){ 
    this->_vars.push_back(var); 
}


void POSCodeGen_CppBlock::append_content(std::string content){
    POS_ASSERT(this->_inner_blocks.size() == 0);
    this->_contents.push_back(content);
}


pos_retval_t POSCodeGen_CppBlock::allocate_block(std::string block_name, bool need_braces, POSCodeGen_CppBlock** new_block){
    pos_retval_t retval = POS_SUCCESS;
    POS_CHECK_POINTER(new_block);
    *new_block = new POSCodeGen_CppBlock(block_name, need_braces, this->_level+1);
    POS_CHECK_POINTER(*new_block);
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
    __insert_empty_line(2);

    for(i=0; i<this->_blocks.size(); i++){
        POS_CHECK_POINTER(this->_blocks[i]);
        this->_blocks[i]->archive();
        __write_block(this->_blocks[i]->archived);
        __insert_empty_line(1);
    }
}
