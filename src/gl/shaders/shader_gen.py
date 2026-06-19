#!/usr/bin/env python3
"""
Automatic converter for GLSL shaders to C string header files.
Run without arguments:
    python gen_all_inc.py
"""

import os

# Mapping: output file -> list of input files
TASKS = {
    "header_vs.inc": ["header.vert"],
    "header_fs.inc": ["header.frag"],
    "im2d_gl.inc": ["im2d.vert"],
    "im3d_gl.inc": ["im3d.vert"],
    "default_vs_gl.inc": ["default.vert"],
    "simple_fs_gl.inc": ["simple.frag"],
    "matfx_gl.inc": ["matfx_env.vert", "matfx_env.frag"],
    "skin_gl.inc": ["skin.vert"],
}

def generate_inc(output_file, input_files):
    """Write one or more input files into a C header as string literals."""
    with open(output_file, 'w', encoding='utf-8') as out:
        for in_file in input_files:
            base = os.path.splitext(os.path.basename(in_file))[0]
            ext = os.path.splitext(in_file)[1][1:].lower()
            suffix = '_vert_src' if ext == 'vert' else '_frag_src' if ext == 'frag' else '_src'
            var_name = base + suffix

            out.write(f'const char *{var_name} =\n')
            with open(in_file, 'r', encoding='utf-8') as f:
                for line in f:
                    line = line.rstrip('\n')
                    out.write(f'"{line}\\n"\n')
            out.write(';\n')

def main():
    for out_file, in_files in TASKS.items():
        missing = [f for f in in_files if not os.path.isfile(f)]
        if missing:
            print(f"Warning: skipping {out_file}, missing input(s): {', '.join(missing)}")
            continue
        print(f"Generating {out_file} <- {' '.join(in_files)}")
        generate_inc(out_file, in_files)
    print("All .inc files generated.")

if __name__ == '__main__':
    main()