# ft_printf  

`ft_printf` is a project from the 42 curriculum that involves reimplementing the standard C `printf` function.  
The goal is to recreate the core behavior of `printf`, including handling format specifiers and variable arguments, without using the standard library's formatting functions.

## 🧠 What I Learned

- Parsing format strings and managing flags
- Handling variadic functions using `stdarg.h`
- Printing various data types (`char`, `string`, `int`, `unsigned`, `hex`, `pointer`)

## ✅ Supported Specifiers

```
%c  %s  %d  %i  %u  %x  %X  %p  %%
```

## 🧪 How to Use

```bash
# 1. Uncomment the main() function in ft_printf2.c

# 2. Compile the project using:
cc -Wall -Wextra -Werror ft_printf1.c ft_printf2.c

# 3. Run the program:
./a.out
```

---


# ft_printf（日本語）

`ft_printf` は、C標準ライブラリの `printf` 関数を**自分で再実装する**42カリキュラムのプロジェクトです。  
可変長引数やフォーマット指定子の処理など、標準関数を使わずに書式付き出力を実装します。

## 🧠 学んだこと

- フォーマット文字列の解析とフラグ処理
- `stdarg.h` を用いた可変長引数の取り扱い
- 複数のデータ型（文字・文字列・整数・符号なし整数・16進数・ポインタ）の出力

## ✅ 対応しているフォーマット指定子

```
%c  %s  %d  %i  %u  %x  %X  %p  %%
```

## 🧪 使い方

```bash
# 1. ft_printf2.c に含まれている main() のコメントアウトを外します

# 2. 以下のようにコンパイルします
cc -Wall -Wextra -Werror ft_printf1.c ft_printf2.c

# 3. 実行します
./a.out
```
