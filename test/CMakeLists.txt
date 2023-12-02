set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  test_algos
  graph/test_node.cc
  graph/test_graph.cc
  graph/test_bfs.cc
  graph/test_dfs.cc
  encoding/test_encoding_table.cc
  encoding/test_huffman_encoding.cc
)

target_link_libraries(
  test_algos
  GTest::gtest_main
)
