#ifndef __IPCBUFFER_H
#define __IPCBUFFER_H

#include <boost/interprocess/managed_shared_memory.hpp>

using namespace boost::interprocess;

class IpcBuffer
{
public:
  IpcBuffer(const char *name, size_t capacity);
  ~IpcBuffer();

  size_t size() const { return size_; }
  size_t capacity() const { return capacity_; }
  size_t write(const uint8_t *data, size_t bytes);
  size_t read(uint8_t *data, size_t bytes);
  void write_nb(const uint8_t *data, size_t bytes);
  void get_write_position(uint64_t& time, uint64_t& position);
  void reset();
  uint8_t *start_ptr();
  const char *name();

private:
  // Note: members can be access from different process
  // only keep information which are common to all processes
  // addresses must be mapped during runtime
  size_t begin_index_, end_index_, size_, capacity_;
  managed_shared_memory::handle_t handle_;
  std::string name_;
  bool blocking_;
  interprocess_mutex wr_position_mutex_;
  uint64_t wr_position_;
  uint64_t wr_time_;
};

#endif
