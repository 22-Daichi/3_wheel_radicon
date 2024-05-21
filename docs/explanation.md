# プログラム解説

## 全体像

本プログラムの`main.cpp`内の`loop()`の実装は以下のようになっています。

```cpp
void loop() {
    Input input = getInput();
    Output output = inputToOutput(input);
    motorA.drive(output.motorA);
    motorB.drive(output.motorB);
    motorC.drive(output.motorC);
}
```

```mermaid

---
config:
    theme: neutral
    fontSize: 20px
---
flowchart TD;
getInput["getInput()"] --> |input| inputToOutput["inputToOutput(input)"]
inputToOutput --> |output.motorA| motorA.drive["motorA.drive(output.motorA)"]
inputToOutput --> |output.motorB| motorB.drive["motorB.drive(output.motorB)"]
inputToOutput --> |output.motorC| motorC.drive["motorC.drive(output.motorC)"]

```

本プログラムは`getInput()`からコントローラの入力`input`を受け取り、`inputOutput()`に引数として与えることで各モータへの出力を得ることを想定して作られています。

したがって、`inputToOutput()`の中身を適切に実装することでラジコンを動かすことができます。

## `inputToOutput()`の概要

### 引数`input`の概要

`inputToOutput()`の引数`input`の型は`Input`で、`Input`のメンバ変数は以下のような構成になっています。

| 変数名     | 説明                                         |
| ---------- | -------------------------------------------- |
| `x`        | コントローラの左スティックの $x$ 軸方向の値  |
| `y`        | コントローラの左スティックの $y$ 軸方向の値  |
| `circle`   | コントローラの〇ボタンが押されているかどうか |
| `square`   | コントローラの□ボタンが押されているかどうか  |
| `cross`    | コントローラの✕ボタンが押されているかどうか  |
| `triangle` | コントローラの△ボタンが押されているかどうか  |

それぞれのメンバ変数には`input.メンバ変数名`でアクセスできます。

### 返り値`output`の概要

`inputToOutput()`の返り値`output`の型は`Output`で、`Output`のメンバ変数は以下のような構成になっています。

| 変数名   | 説明                    |
| -------- | ----------------------- |
| `motorA` | モータAへの出力 (0~255) |
| `motorB` | モータBへの出力 (0~255) |
| `motorC` | モータCへの出力 (0~255) |

それぞれのメンバ変数には`output.メンバ変数名`でアクセスできます。

また、モータA, B, Cに繋がっている車輪の配置は以下のようになっています。

![](assets/3_wheel_radicon.png)

### `output`の計算ヒント

#### 並進( $x$ , $y$ 軸方向)

$x$軸方向に機体を進めたいときには

![](assets/3_wheel_radicon_wheel.png)

図のように「機体を進めたい量」に $\cos\theta$ をかけた値が「車輪の出力」になります。(※ $\theta$ : 車輪の角度)

また、同様に $y$ 軸方向に機体を進めたいときには「機体を進めたい量」に $\sin\theta$ をかけた値が「車輪の出力」になります。

さらに、 $x$ 軸方向,  $y$ 軸方向それぞれへの「進めたい量」はベクトルとして足し合わせができます (**線形性**)。

つまり、「 $x$ 軸方向に $a$ , $y$ 軸方向に $b$ 進めたい」ときには、車輪への出力は

$$
a\cos\theta + b\sin\theta
$$

となります。

#### 旋回

全ての車輪を正方向に同じだけ回転させると反時計回りに旋回します。

逆に、全ての車輪を逆方向に同じだけ回転させると時計回りに旋回します。

また、旋回のための出力もまた $x$ 軸方向, $y$ 軸方向それぞれへの「進めたい量」との足し合わせが可能です。(**線形性**)

したがって、「 $x$ 軸方向に $a$ , $y$ 軸方向に $b$ 進めながら $c$ だけ旋回させたい」ときには、車輪への出力は

$$
a\cos\theta + b\sin\theta + c
$$

となります。
