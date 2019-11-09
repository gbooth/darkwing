/*
* CPSC 2720 Fall 2018
* Copyright 2018 <Navi>
*/

#ifndef EXCEPTIONS_H_INCLUDED
#define EXCEPTIONS_H_INCLUDED

#include <stdexcept>

/**
* Exception for when an ID doesn't match the expected ID type
*/
class invalid_id: public std::runtime_error {
 public:
  /**
  * @param errMessage An error message.
  */
  explicit invalid_id(const char* errMessage) :
    std::runtime_error(errMessage) {
  }
};

/**
* Exception for when a required reference file is missing
*/
class file_error: public std::runtime_error {
 public:
  /**
  * @param errMessage An error message.
  */
  explicit file_error(const char* errMessage) :
    std::runtime_error(errMessage) {
  }
};

/**
* exception for if you set invalid position
*/
class invalid_pos: public std::runtime_error {
 public:
  /**
  * @param errMessage An error message.
  */
  explicit invalid_pos(const char* errMessage) :
    std::runtime_error(errMessage) {
  }
};


#endif  // EXCEPTIONS_H_INCLUDED
