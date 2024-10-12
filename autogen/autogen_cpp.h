#pragma once

#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>

#include "utils.h"

#include "pos/include/common.h"
#include "pos/include/log.h"

/*!
 *  \brief  contains a C++ block's content
 */
class POSCodeGen_CppBlock {
 public:
    /*!
     *  \brief  constructor
     *  \param  block_name          name of this block
     *  \param  need_braces         whether it needs braces to wrap this block
     *  \param  need_foot_comment   whether the block need footnote comment
     *  \param  level               level of this block
     */
    POSCodeGen_CppBlock(std::string block_name, bool need_braces=true, bool need_foot_comment=false, uint8_t level=0) 
        : _block_name(block_name), _need_braces(need_braces), _need_foot_comment(need_foot_comment), _level(level), archived("")
    {
        if(unlikely(this->_need_braces == false and this->_block_name.size() > 0)){
            POS_WARN_C("uncorrect cpp block configuration: declare named block without braces, refine as brace needed");
            this->_need_braces = true;
        }
    }
    ~POSCodeGen_CppBlock() = default;

    // archived this block after (after all blocks are inserted)
    std::string archived;

    /*!
     *  \brief  archive this block (after all blocks are inserted)
     */
    void archive();

    /*!
     *  \brief  declare new variable in this block
     *  \param  var the newly add variable
     */
    void declare_var(std::string var);

    /*!
     *  \brief  allocate new inner block of this block
     *  \param  block_name          name of the new block
     *  \param  new_block           pointer to the newly created block
     *  \param  need_braces         whether it needs braces to wrap this block
     *  \param  need_foot_comment   whether the new block need footnote comment
     *  \param  level_offset        offset of the new block based on current block's level
     *  \return POS_SUCCESS for succesfully generation
     */
    pos_retval_t allocate_block(
        std::string block_name, POSCodeGen_CppBlock** new_block, bool need_braces=true, bool need_foot_comment=false, int level_offset=1
    );
    
    /*!
     *  \brief  append content to this block
     *  \note   only leaf node can have content
     *  \param  content the content to be appended
     */
    void append_content(std::string content);

 private:
    // all variables declarations in this block
    std::vector<std::string> _vars;

    // other inner block in this block
    std::vector<POSCodeGen_CppBlock*> _inner_blocks;

    // content of this block
    // only leaf node can have content
    std::vector<std::string> _contents;

    // name of this block
    std::string _block_name;

    // mark whetehr this block need braces to wrap
    bool _need_braces;

    // mark whether this block need footnote comment
    bool _need_foot_comment;

    uint8_t _level;
};


/*! 
 *  \brief  contains a C++ source file's content
 */
class POSCodeGen_CppSourceFile {
 public:
    /*!
     *  \brief  constructor
     *  \param  file_path   path to the generated file
     */
    POSCodeGen_CppSourceFile(std::string file_path){
        this->_file_stream.open(file_path, std::ios::trunc);
        if(unlikely(!this->_file_stream)){
            POS_WARN_C("failed to create new file: path(%s)", file_path.c_str());
        }
    }
    ~POSCodeGen_CppSourceFile(){
        if(likely(this->_file_stream)){
            this->_file_stream.close();
        }
    }

    // archived this file after all content generated
    std::string archived;

    /*!
     *  \brief  declare new include in this block
     *  \param  var the newly add include
     */
    void add_include(std::string include);

    /*!
     *  \brief  add a new block to this block
     *  \param  block   the newly add block
     */
    void add_block(POSCodeGen_CppBlock* block);
    
    /*!
     *  \brief  archive and write to the file (after all blocks are inserted)
     */
    void archive();

 private:
    // file stream to the output file
    std::ofstream _file_stream;

    // all include headers of this source file
    std::vector<std::string> _includes;

    // all blocks of this source file
    std::vector<POSCodeGen_CppBlock*> _blocks;
};
