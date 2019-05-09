/*
 * @Author: messi
 * @LastAuthor: Do not edit
 * @Description:
 * @since: 2019-05-10 00:47:46
 * @lastTime: 2019-05-10 02:06:59
 */
#include "db_manager.h"
#include <vector>

// using namespace soci;

DbManager::DbManager(const std::string& backend_name,
                     const std::string& connect_string)
    : session_(backend_name, connect_string), statement_(session_) {}

// template <typename T>
// void DbManager::ExchangeInto(T arg) {
//   statement_.exchange(soci::into(arg));
// }

// template <typename T>
// void DbManager::ExchangeUse(T arg) {
//   statement_.exchange(soci::use(arg));
// }

bool DbManager::Execute() { return statement_.execute(true); }
void DbManager::Prepare(std::string const& query) {
  statement_.alloc();
  statement_.prepare(query);
  statement_.define_and_bind();
}