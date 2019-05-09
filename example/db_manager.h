/*
 * @Author: messi
 * @LastAuthor: Do not edit
 * @Description:
 * @since: 2019-05-10 00:45:55
 * @lastTime: 2019-05-10 01:45:01
 */
#include <string>
#include "soci/session.h"

class DbManager {
 public:
  DbManager(const std::string& backend_name, const std::string& connect_string);
  bool Execute();
  void Prepare(std::string const& query);
  template <typename T>
  void ExchangeInto(T arg) {
    statement_.exchange(soci::into(arg));
  }
  template <typename T>
  void ExchangeUse(T arg) {
    statement_.exchange(soci::use(arg));
  }

  DbManager() : statement_(session_) {}
  ~DbManager() {}
  bool Open(std::string const& backendName, std::string const& connectString) {}

 private:
  soci::session session_;
  soci::statement statement_;
};