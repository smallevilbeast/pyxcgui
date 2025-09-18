import os


def getRootPath():
    return os.path.dirname(os.path.dirname(os.path.dirname(__file__)))


def getResource(*args):
    return os.path.join(getRootPath(), "resources", *args)
