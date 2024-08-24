from setuptools import find_packages
from setuptools import setup

setup(
    name='stereo',
    version='0.0.0',
    packages=find_packages(
        include=('stereo', 'stereo.*')),
)
