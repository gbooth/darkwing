/*
* CPSC 2720 Fall 2018
* Copyright 2018 Dr. Anvik <john.anvik@uleth.ca>
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
  explicit widget_operation_failed_error(const char* errMessage) :
    std::runtime_error(errMessage) {
  }
};

/**
* Exception for when a required reference file is missing
*/
class missing_file: public std::runtime_error {
 public:
  /**
  * @param errMessage An error message.
  */
  explicit widget_error(const char* errMessage) :
    std::runtime_error(errMessage) {
  }
};

#endif  // EXCEPTIONS_H_INCLUDED
