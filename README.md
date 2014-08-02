LIBMEMEPOOL
===========

Libmemepool provides support for modeling data and information as memes, allowing them to evolve and propagate around a system. Also included is a method of extracting the meme information in human readable form.

This is probably the third attempt at writing a similar library. The previous attempts tried to create the system from the bottom up. That is, writing a basic evolutionary system before having reasonable and representative output. This lead to the system being difficult to test. This iteration started with the top down, so I am first attempting to create an expressive system for the memes to be represented by. As such, the evolutionary "memetic" system may not materialise until significantly later.

Targets:
--------

libmemepool.(a,so,dylib,lib,dll) - The actual memepool library. There are static and dynamic versions for each platform so that they can easily be integrated with any project. Should not have any prerequisites other than libc.

tests(,.exe) - Simple testsuite of the features of libmemepool. Statically linked

libgossip.(a,so,dylib,lib,dll) - TODO - Will contain the libmemepool library, with a C++ wrapper and helpers to easy create a "gossip" system as per my previous projects. Might also contain simple script support and scraper support to build wordlists and constructs automatically from web services.

FEATURES:
---------
- Basic meme term output
- Language constructs

TODO:
-----
- Everything
- Meme propagation
- Meme evolution
- Gossip library