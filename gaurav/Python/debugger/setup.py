from setuptools import setup, find_packages

setup(
    name='debugger',
    version='0.1',
    packages=find_packages(),
    install_requires=[
        'colorama',
    ],
    author='Gaurav Rana',
    author_email='ranaofficial05@gmail.com',
    description='A package for debugging.',
    long_description=open('README.md').read(),
    long_description_content_type='text/markdown',
    url='https://github.com/yourusername/debug_printer',
    classifiers=[
        'Programming Language :: Python :: 3',
        'License :: OSI Approved :: MIT License',
        'Operating System :: OS Independent',
    ],
    python_requires='>=3.6',
)
