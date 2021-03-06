#ifndef CONFLUO_ATOMIC_MULTILOG_ARCHIVAL_ARCHIVER_H_
#define CONFLUO_ATOMIC_MULTILOG_ARCHIVAL_ARCHIVER_H_

#include "container/data_log.h"
#include "monolog_linear_archiver.h"
#include "filter_log.h"
#include "filter_log_archiver.h"
#include "index_log.h"
#include "index_log_archiver.h"
#include "read_tail.h"

namespace confluo {
namespace archival {

class atomic_multilog_archiver {
 public:
  atomic_multilog_archiver();

  /**
   * Constructor.
   * @param path directory to store archives in or where archives are currently stored
   * @param rt data log read tail
   * @param log data log
   * @param filters atomic multilog filters
   * @param indexes atomic multilog indexes
   * @param schema data log schema
   * @param clear
   */
  atomic_multilog_archiver(const std::string &path,
                           read_tail rt,
                           data_log *log,
                           filter_log *filters,
                           index_log *indexes,
                           schema_t *schema,
                           bool clear = true);

  /**
   * Attempt to archive data log, filters and indexes
   * up to a particular data log offset. Best effort.
   * Does not allow for archival past the read tail.
   * @param offset data log offset
   */
  void archive(size_t offset);

  /**
   *
   * @return offset up to which data log has been archived
   */
  size_t tail();

  /**
   *
   * @return path of directory in which data log archives are stored
   */
  std::string data_log_path();

  /**
   *
   * @return path of directory in which filter log archives are stored
   */
  std::string filter_log_path();

  /**
   *
   * @return path of directory in which index log archives are stored
   */
  std::string index_log_path();

 private:
  std::string path_;
  read_tail rt_;
  size_t record_size_;
  data_log_archiver data_log_archiver_;
  filter_log_archiver filter_log_archiver_;
  index_log_archiver index_log_archiver_;

};

}
}

#endif /* CONFLUO_ATOMIC_MULTILOG_ARCHIVAL_ARCHIVER_H_ */
