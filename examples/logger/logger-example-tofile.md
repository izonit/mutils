Example output:
```sh
[DEBUG]: Succesfully closed file stream
```

Why so? Because the FileHandler class' destructor outputs this if it manages to close the fstream.
If everything is correct, the file output.txt will also be created with these contents:

```sh
[INFO]: Logger works
```