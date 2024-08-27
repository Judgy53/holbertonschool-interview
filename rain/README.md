# rain

Given a list of non-negative integers representing the heights of walls with unit width 1, as if viewing the cross-section of a relief map, calculate how many square units of water will be retained after it rains.

- Prototype: `def rain(walls)`
- `walls` is a list of non-negative integers.
- Return: Integer indicating total amount of rainwater retained.
- Assume that the ends of the list (before index 0 and after index walls\[-1\]) are **not** walls, meaning they will not retain water.
- If the list is empty return `0`.

```sh
$ ./0_main.py
6
6
$
```

Visual representation of the walls `[0, 1, 0, 2, 0, 3, 0, 4]`

![](https://s3.eu-west-3.amazonaws.com/hbtn.intranet/uploads/medias/2021/4/85ef782020ac6efdc7004b62ea86724a552285b4.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIA4MYA5JM5DUTZGMZG%2F20240827%2Feu-west-3%2Fs3%2Faws4_request&X-Amz-Date=20240827T093655Z&X-Amz-Expires=86400&X-Amz-SignedHeaders=host&X-Amz-Signature=6b0bda782cac7749ecd78c9373ec795eb897dfd06b14853009248a500d0449c5)

Visual representation of the walls `[2, 0, 0, 4, 0, 0, 1, 0]`

![](https://s3.eu-west-3.amazonaws.com/hbtn.intranet/uploads/medias/2021/4/9a27c3e4e214e55b3c0b8b1439fdc99b4a184ff5.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIA4MYA5JM5DUTZGMZG%2F20240827%2Feu-west-3%2Fs3%2Faws4_request&X-Amz-Date=20240827T093655Z&X-Amz-Expires=86400&X-Amz-SignedHeaders=host&X-Amz-Signature=d89acf948fbc98c9390a465e948e62458f183963013d8ad6912866c01e78e2ff)


- File: `0-rain.py`
