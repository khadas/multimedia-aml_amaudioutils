#include <boost/interprocess/managed_shared_memory.hpp>

#define AudioServerShmemSize (16 * 1024 * 1024)

using namespace boost::interprocess;

class audio_server_shmem {
  private:
    audio_server_shmem(bool is_server) {
      if (is_server)
        shm_ = new managed_shared_memory(open_or_create, "AudioServiceShmem", AudioServerShmemSize);
      else
        shm_ = new managed_shared_memory(open_only, "AudioServiceShmem");
    }
    ~audio_server_shmem() {
      delete shm_;
    }
    static managed_shared_memory *shm_;
  public:
    audio_server_shmem(const audio_server_shmem &) = delete;
    audio_server_shmem(audio_server_shmem &&) = delete;
    audio_server_shmem& operator=(const audio_server_shmem&) = delete;
    audio_server_shmem& operator=(audio_server_shmem&&) = delete;

    static managed_shared_memory * getInstance(bool is_server = false) {
      static audio_server_shmem instance(is_server);
      return shm_;
    }
};
