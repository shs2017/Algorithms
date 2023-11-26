set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  test_algos
  graph/test_binary_node.cc
  graph/test_bfs.cc
  graph/test_dfs.cc
  graph/test_priority_binary_node.cc
  graph/test_huffman_coding.cc
)

target_link_libraries(
  test_algos
  GTest::gtest_main
)
