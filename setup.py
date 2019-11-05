from distutils.core import setup
from the_doomed_ship import __version__

setup(name='the_doomed_ship',
      version=__version__,
      description='An adventure game',
      python_requires='>=3.7',
      url='http://github.com/F-S-C/The-Doomed-Ship',
      author='FSC - Five Students of Computer Science',
      author_email='',
      license='GNU GPLv3',
      packages=['the_doomed_ship'],
      zip_safe=False,
      entry_points={
          'console_scripts': [
              'the-doomed-ship = the_doomed_ship.__main__:main',
          ],
      }
      )
