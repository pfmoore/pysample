from _cffiex import lib

def test_simple():
    assert lib.GetVersion() != 0
