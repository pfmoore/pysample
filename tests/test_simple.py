# import sample
from _cffiex import ffi, lib

def test_simple():
    # assert True
    assert lib.GetVersion() != 0
