/**
 * Autogenerated by Thrift Compiler (0.13.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "cellState_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>



int _kCellStateValues[] = {
  CellState::Empty,
  CellState::O,
  CellState::X
};
const char* _kCellStateNames[] = {
  "Empty",
  "O",
  "X"
};
const std::map<int, const char*> _CellState_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(3, _kCellStateValues, _kCellStateNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const CellState::type& val) {
  std::map<int, const char*>::const_iterator it = _CellState_VALUES_TO_NAMES.find(val);
  if (it != _CellState_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const CellState::type& val) {
  std::map<int, const char*>::const_iterator it = _CellState_VALUES_TO_NAMES.find(val);
  if (it != _CellState_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

