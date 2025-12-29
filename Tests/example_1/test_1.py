import subprocess
from pathlib import Path
import sys

project_root = Path(r"C:\Users\William\STM32CubeIDE\workspace_1.8.0\F4VE")
example = project_root / "Tests" / "example_1"
application = project_root / "Application"

image = "g++:latest"
binary = "helloworld"

def run(cmd):
    print(">>", " ".join(cmd))
    result = subprocess.run(cmd, capture_output=True, text=True)
    if result.returncode != 0:
        print("❌ ERRORE:")
        print(result.stderr)
        sys.exit(1)
    return result

docker_path = "/usr/src/myapp"

# ---------------- COMPILAZIONE ----------------
compile_cmd = [
    "docker", "run", "--rm",
    "-v", f"{project_root}:{docker_path}",        # monta tutto il progetto
    "-w", f"{docker_path}/Tests/example_1",      # working dir nel container
    image,
    "g++",
    "-I" + f"{docker_path}/Application",         # include path corretto
    "helloworld.c",                              # main
    f"{docker_path}/Application/app.cpp",        # source da linkare
    "-o", binary
]

run(compile_cmd)

# ---------------- ESECUZIONE ----------------
run_cmd = [
    "docker", "run", "--rm",
    "-v", f"{project_root}:{docker_path}",
    "-w", f"{docker_path}/Tests/example_1",
    image,
    f"./{binary}"
]

result = run(run_cmd)
print("OUTPUT:")
print(result.stdout)