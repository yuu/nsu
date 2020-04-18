# enum のスコープ (Enumeration scope)

tag: c++11

enum class およびenum structでスコープ付きのenumを定義できるようになった。

```cpp
enum class Fruits {
    apple,
    strawberry,
};

// type::member でアクセス
Fruits f = Fruits::apple;

// スコープにより同名◯
Fruits apple = Fruits::apple;
```

## 内部型の指定が可能に
デフォルトの内部型

* 古いenum
    => 処理系依存

* enum class
    => int


8bit 指定
```cpp
enum class Fruits : uint8_t {
    apple,
    strawberry,
}
```

指定型以外はError
```cpp
enum class Fruits : uint8_t {
    apple = -1,         // X マイナス値は入らない
    strawberry = 1000,  // 最大値を超えている
}
```

## 内部型の取得が可能に
```cpp
// 内部型の変更でこの処理の修正する必要があり、見落としがちな修正箇所
uint8_t a = static_cast<utin8_t>(Fruits::apple);

// type safety で内部型を直接指定せずに cast
using Fruits_t = std::underlying_type<Fruits>::type;
Fruits_t apple = static_cast<Fruits_t>(Fruits::apple);
```

## 前方宣言が可能に
enumは内部型を指定した場合のみ前方宣言が可能
```cpp
enum A;         // ☓
enum A : int;   // ◯
```

```cpp
enum class A;       // ◯
enum class B : int  // ◯
```
