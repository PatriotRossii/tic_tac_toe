/**
 * Autogenerated by Thrift Compiler (0.13.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "cell_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>




Cell::~Cell() noexcept {
}


void Cell::__set_row(const int64_t val) {
  this->row = val;
}

void Cell::__set_column(const int64_t val) {
  this->column = val;
}

void Cell::__set_state(const  ::CellState::type val) {
  this->state = val;
}
std::ostream& operator<<(std::ostream& out, const Cell& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t Cell::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->row);
          this->__isset.row = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->column);
          this->__isset.column = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast0;
          xfer += iprot->readI32(ecast0);
          this->state = ( ::CellState::type)ecast0;
          this->__isset.state = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t Cell::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("Cell");

  xfer += oprot->writeFieldBegin("row", ::apache::thrift::protocol::T_I64, 1);
  xfer += oprot->writeI64(this->row);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("column", ::apache::thrift::protocol::T_I64, 2);
  xfer += oprot->writeI64(this->column);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("state", ::apache::thrift::protocol::T_I32, 3);
  xfer += oprot->writeI32((int32_t)this->state);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(Cell &a, Cell &b) {
  using ::std::swap;
  swap(a.row, b.row);
  swap(a.column, b.column);
  swap(a.state, b.state);
  swap(a.__isset, b.__isset);
}

Cell::Cell(const Cell& other1) {
  row = other1.row;
  column = other1.column;
  state = other1.state;
  __isset = other1.__isset;
}
Cell& Cell::operator=(const Cell& other2) {
  row = other2.row;
  column = other2.column;
  state = other2.state;
  __isset = other2.__isset;
  return *this;
}
void Cell::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "Cell(";
  out << "row=" << to_string(row);
  out << ", " << "column=" << to_string(column);
  out << ", " << "state=" << to_string(state);
  out << ")";
}


