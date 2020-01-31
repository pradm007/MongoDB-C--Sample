#include <bits/stdc++.h>
#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>

using bsoncxx::builder::stream::close_array;
using bsoncxx::builder::stream::close_document;
using bsoncxx::builder::stream::document;
using bsoncxx::builder::stream::finalize;
using bsoncxx::builder::stream::open_array;
using bsoncxx::builder::stream::open_document;
using namespace std;

int main() {

  cout << "Hello " << endl;

  try {
    mongocxx::instance instance{}; // This should be done only once.
    mongocxx::uri uri("mongodb://localhost:27017");
    mongocxx::client client(uri);

    mongocxx::database db = client["mydb_trial"];
    mongocxx::collection detail_collection = db["detail"];

    auto builder = bsoncxx::builder::stream::document{};
    bsoncxx::document::value doc_value =
        builder << "name"
                << "Hello World"
                << "lucky_number" << 7 << bsoncxx::builder::stream::finalize;

    bsoncxx::document::view doc_view = doc_value.view();

    detail_collection.insert_one(doc_view);
  } catch (exception e) {
    cout << "error " << e.what() << endl;
  }

  return 0;
}