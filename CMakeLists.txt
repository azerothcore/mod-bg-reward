# Set current dir
CU_SET_PATH("CUR_DIR_MODULE" "${CMAKE_CURRENT_LIST_DIR}")

AC_ADD_SCRIPT("${CUR_DIR_MODULE}/src/BGReward.cpp")
AC_ADD_SCRIPT_LOADER("BGReward" "${CUR_DIR_MODULE}/src/loader.h")
CU_ADD_HOOK(AFTER_WORLDSERVER_CMAKE "${CUR_DIR_MODULE}/src/cmake/after_ws_install.cmake")