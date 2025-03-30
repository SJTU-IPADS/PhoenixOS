import argparse
import subprocess

SUBMODULE_MAP = {
    "third_party/cuda-checkpoint": {
        "gitlab": {
            "url": "https://ipads.se.sjtu.edu.cn:1312/scaleaisys/phoenixos-submodules/cuda-checkpoint.git",
            "branch": "main"
        },
        "github": {
            "url": "https://github.com/NVIDIA/cuda-checkpoint.git",
            "branch": "main"
        }
    },
    "third_party/googletest": {
        "gitlab": {
            "url": "https://ipads.se.sjtu.edu.cn:1312/scaleaisys/phoenixos-submodules/googletest.git",
            "branch": "main"
        },
        "github": {
            "url": "https://github.com/google/googletest.git",
            "branch": "main"
        }
    },
    "third_party/yaml-cpp": {
        "gitlab": {
            "url": "https://ipads.se.sjtu.edu.cn:1312/scaleaisys/phoenixos-submodules/yaml-cpp.git",
            "branch": "master"
        },
        "github": {
            "url": "https://github.com/jbeder/yaml-cpp.git",
            "branch": "master"
        }
    },
    "third_party/protobuf": {
        "gitlab": {
            "url": "https://ipads.se.sjtu.edu.cn:1312/scaleaisys/phoenixos-submodules/protobuf.git",
            "branch": "main"
        },
        "github": {
            "url": "https://github.com/protocolbuffers/protobuf.git",
            "branch": "main"
        }
    },
    "third_party/criu": {
        "gitlab": {
            "url": "https://ipads.se.sjtu.edu.cn:1312/scaleaisys/phoenixos-submodules/criu.git",
            "branch": "adapt_cuda_checkpoint"
        },
        "github": {
            "url": "https://github.com/SJTU-IPADS/PhoenixOS-CRIU.git",
            "branch": "adapt_cuda_checkpoint"
        }
    },
    "third_party/util-linux": {
        "gitlab": {
            "url": "https://ipads.se.sjtu.edu.cn:1312/scaleaisys/phoenixos-submodules/util-linux.git",
            "branch": "master"
        },
        "github": {
            "url": "https://github.com/util-linux/util-linux.git",
            "branch": "master"
        }
    },
    "remoting": {
        "gitlab": {
            "url": "https://ipads.se.sjtu.edu.cn:1312/scaleaisys/xpuremoting.git",
            "branch": "main"
        },
        "github": {
            "url": "https://github.com/SJTU-IPADS/PhoenixOS-Remoting.git",
            "branch": "main"
        }
    }
}


MAIN_REPO_MAP = {
    "gitlab": "git@ipads.se.sjtu.edu.cn:scaleaisys/phoenixos.git",
    "github": "git@github.com:SJTU-IPADS/PhoenixOS.git"
}


def update_main_remote(direction):
    target = direction
    new_url = MAIN_REPO_MAP[target]

    try:
        result = subprocess.run(
            ["git", "remote", "get-url", "origin"],
            capture_output=True,
            text=True,
            check=True
        )
        current_url = result.stdout.strip()
        
        if current_url == new_url:
            print(f"remote origin is aleady been set as {new_url}")
            return

        subprocess.run(
            ["git", "remote", "set-url", "origin", new_url],
            check=True
        )
        print(f"set remote origin as {new_url}")
        
    except subprocess.CalledProcessError as e:
        print(f"failed to set remote origin as {new_url}, error: {e}")
        raise


def convert_gitmodules(direction):
    target = direction
    
    try:
        with open('.gitmodules', 'r') as f:
            lines = f.readlines()
    except FileNotFoundError:
        print("Error: .gitmodules file not found!")
        return

    new_lines = []
    i = 0
    while i < len(lines):
        line = lines[i]
        stripped = line.strip()
        
        if stripped.startswith('[submodule '):
            try:
                path = stripped.split('"')[1]
            except IndexError:
                new_lines.append(line)
                i += 1
                continue

            new_lines.append(line)
            i += 1
            
            # Get github configuration
            config = SUBMODULE_MAP.get(path, {}).get(target, {})
            new_url = config.get('url', '')
            new_branch = config.get('branch', None)
            
            url_updated = False
            branch_updated = False
            
            while i < len(lines) and (lines[i].startswith(('\t', ' '))):
                current_line = lines[i]
                stripped_line = current_line.strip()
                
                if stripped_line.startswith('url'):
                    # Update URL
                    new_lines.append(f'\turl = {new_url}\n')
                    url_updated = True
                    i += 1
                elif stripped_line.startswith('branch'):
                    # Handle branch
                    if new_branch is not None:
                        new_lines.append(f'\tbranch = {new_branch}\n')
                    branch_updated = True
                    i += 1
                else:
                    # Preserve other settings
                    new_lines.append(current_line)
                    i += 1
            
            # Add missing URL if not updated
            if not url_updated:
                new_lines.append(f'\turl = {new_url}\n')
            
            # Add branch if needed
            if new_branch is not None and not branch_updated:
                new_lines.append(f'\tbranch = {new_branch}\n')
        else:
            new_lines.append(line)
            i += 1

    # Write modified content back
    with open('.gitmodules', 'w') as f:
        f.writelines(new_lines)
    
    # Update git submodules
    try:
        subprocess.run(['git', 'submodule', 'sync'], check=True)
        print("Submodule URLs synchronized successfully.")
        print("You may need to run: git submodule update --init --remote --force")
    except subprocess.CalledProcessError as e:
        print(f"Error running git submodule sync: {e}")

def main():
    parser = argparse.ArgumentParser(
        description='Convert git submodules between gitlab and github repositories',
        formatter_class=argparse.ArgumentDefaultsHelpFormatter)
    parser.add_argument('direction', choices=['github', 'gitlab'],
                       help='Conversion direction: to-github converts to GitHub URLs, to-gitlab reverts to original URLs')
    args = parser.parse_args()
    
    convert_gitmodules(args.direction)
    update_main_remote(args.direction)

if __name__ == '__main__':
    main()
