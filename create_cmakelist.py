from glob import glob

folders = glob("Task */")
blocks = []
bias = 0

for folder in folders:
    cur_files_list = [file.replace("\\", "/") for file in list(glob(f"{folder}*.cpp"))]
    for idx, file in enumerate(cur_files_list):
        block = f"""
set(BUILD_{bias + idx + 1} {file.split("/")[-1]})
set(SOURCE_FILES_{bias + idx + 1} "{file}")
add_executable(${{BUILD_{bias + idx + 1}}} ${{SOURCE_FILES_{bias + idx + 1}}})
"""
        blocks.append(block)

    bias += len(cur_files_list)

header = """cmake_minimum_required(VERSION 3.3)
project(test_build)

set(CMAKE_CXX_STANDARD 14)
"""

with open("CMakeLists.txt", "w") as f:
    f.write(f"{header}\n {''.join(blocks)}")
