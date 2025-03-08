# [Mutils](https://github.com/izonit/mutils)
**An amateur project, created to simplify routine.** Created by [mizorint](https://x.com/mizorint).

## Installation and usage
To install the library, clone the repository, and `cd` into  it:
```sh
git clone https://github.com/izonit/mutils && cd mutils/
```

Build the library:
```sh
cmake --build build/
```

After that, install the library globally:
```sh
sudo cmake --install build/
```

When in the cloned repository, run `sudo make install` - it will globally install the library. To see mutils' practical usage, refer to [examples](https://github.com/izonit/mutils/examples).

> [!NOTE]
> Looking for documentation? Look at the header files, they provide short description of what functions do.

## FAQ
> Q: What is Mutils?

Mutils is a static library, consisting of classes, aliases, functions and types created to simplify your routine of writing code. It's Boost, but etremely small.

> Q: Why Mutils?

Mutils tries to be small and simple. In fact, its code is so simple that you can understand its source code without effort. Documentation is present as well.

> Q: Windows support?

Not tested. Not planned on being tested, neither. You can try, though.

> Q: What do I do if I encounter a bug?

If you encounter a bug, please open an issue explaining it. PRs are welcome as well.

> Q: What does the name stand for?

Mutils (pronounced as `muˈti:ls`) is a short-hand alias for **M**izo**Utils**. And Mizo is one of my nicknames.

> Q: What are the empty `//` comments in the code?

I use the empty comments to prevent clang-format from formatting certain things as a one-liner, which sometimes is unwanted and infuriating.

## TODO
- `!!!` Improve the documentation overall (and, preferrably, add docs to the source files as well)
- Add a logger - with a number of log levels to select from (with safety, efficiency and use in mind)
- Integrate GTest to catch bugs automatically

## Known bugs
- None yet.