/*
 * @Author: messi
 * @LastAuthor: Do not edit
 * @Description:
 * @since: 2019-05-09 23:58:09
 * @lastTime: 2019-05-10 02:25:26
 */
#include <iostream>
#include <string>
#include "db_manager.h"
#include "soci/mysql/soci-mysql.h"
#include "soci/soci.h"

using namespace std;
using namespace soci;

int main() {
  // session sql("mysql",
  //             "dbname=test user=root password=123456 "
  //             "host=127.0.0.1 port=3306");

  // string first_name = "Steve";
  // string second_name = "Jobs";
  // sql << "insert into Person(first_name, second_name)"
  //        " values(:first_name, :second_name)",
  //     use(first_name), use(second_name);
  // long id;
  // sql.get_last_insert_id("Person", id);

  // // select
  // int id2 = 1;
  // sql << "select first_name, second_name from Person where id=:id ",
  // use(id2),
  //     into(first_name), into(second_name);
  // if (!sql.got_data()) {
  //   cout << "no record" << endl;
  // }

  // rowset<row> rs = (sql.prepare << "select * from Person");
  // for (rowset<row>::iterator it = rs.begin(); it != rs.end(); ++it) {
  //   const row& row = *it;
  //   cout << "id:" << row.get<long long>(0)
  //        << " first_name:" << row.get<string>(1)
  //        << " last_name:" << row.get<string>(2) << endl;
  // }

  DbManager db_manager(
      "mysql",
      "dbname=test user=root password=123456 host=127.0.0.1 port=3306");

  std::string first_name;
  int id = 1;
  db_manager.ExchangeInto(first_name);
  db_manager.ExchangeUse(id);
  db_manager.Prepare("select first_name from Person where id=:id");
  if (!db_manager.Execute()) {
    std::cout << "Execute error!" << std::endl;
  }

  std::cout << first_name << std::endl;

  // session sql("mysql",
  //             "dbname=test user=root password=123456 "
  //             "host=127.0.0.1 port=3306");

  // int id = 1;
  // string name;

  // statement st(sql);
  // st.exchange(into(name));
  // st.exchange(use(id));
  // st.alloc();
  // st.prepare("select first_name from Person where id=:id");
  // st.define_and_bind();
  // if (!st.execute(true)) {
  //   std::cout << "Execute error!" << std::endl;
  // }
  // std::cout << name << std::endl;

  return 0;
}