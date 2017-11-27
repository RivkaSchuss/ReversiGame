file(REMOVE_RECURSE
  "test_main.cpp.pdb"
  "test_main.cpp"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/test_main.cpp.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
