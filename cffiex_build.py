from cffi import FFI
ffi = FFI()

ffi.set_source("_cffiex",
    """
    #include <windows.h>
    """,
    libraries=[])   # or a list of libraries to link with
    # (more arguments like setup.py's Extension class:
    # include_dirs=[..], extra_objects=[..], and so on)

ffi.cdef("""
    DWORD WINAPI GetVersion(void);
""")

if __name__ == "__main__":
    ffi.compile()
