# Copyright (C) 2019 FSC
#
# This file is part of The Doomed Ship.
#
# The Doomed Ship is free software: you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by the Free
# Software Foundation, either version 3 of the License, or (at your option) any
# later version.
#
# The Doomed Ship is distributed in the hope that it will be useful, but WITHOUT
# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
# FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License along with
# The Doomed Ship. If not, see <http://www.gnu.org/licenses/>.

from setuptools import setup, find_packages

import the_doomed_ship

with open("README.md", "r") as f:
    long_description = f.read()

setup(
    name='The-Doomed-Ship',
    version=the_doomed_ship.__version__,
    license=the_doomed_ship.__license__,
    author=the_doomed_ship.__author__,
    author_email='email',
    description='''"L'Astronave Condannata: un'avventura" is a game created by Enrico Colombini and Chiara Tovena, released as freeware and modified (with the author's permission) by the team FSC''',
    long_description=long_description,
    long_description_content_type='text/markdown',
    url='https://github.com/F-S-C/The-Doomed-Ship',
    packages=find_packages(),
    install_requires=[],
    classifiers=[
        'Programming Language :: Python :: 3',
        'License :: OSI Approved :: GNU General Public License v3 (GPLv3)',
        'Topic :: Games/Entertainment :: Role-Playing',
    ],
    entry_points={
        'console_scripts': ['the-doomed-ship=the_doomed_ship.__main__:main'],
    },
    python_requires='>3',
)
