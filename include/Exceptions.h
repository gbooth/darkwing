/**
 *@author Ben Hunt
 *@date 2019-11git a
 */

#ifndef EXCEPTIONS_H_INCLUDED
#define EXCEPTIONS_H_INCLUDED

#include <stdexcept>

/**
* Exception for when an ID doesn't match the expected ID type.
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

/**
* exception for combat error
*/
class combat_error: public std::runtime_error {
 public:
  /**
  * @param errMessage An error message.
  */
  explicit combat_error(const char* errMessage) :
    std::runtime_error(errMessage) {
  }
};

/**
* exception for save error
*/
class save_error: public std::runtime_error {
 public:
  /**
  * @param errMessage An error message.
  */
  explicit save_error(const char* errMessage) :
    std::runtime_error(errMessage) {
  }
};

#endif  // EXCEPTIONS_H_INCLUDED
