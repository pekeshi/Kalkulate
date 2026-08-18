# Kalkulate V2

A command-line calculator built in C++ that supports basic arithmetic operations, exponentiation, and parentheses.

## Features

- **Basic Operations**: Addition (`+`), subtraction (`-`), multiplication (`*`), division (`/`)
- **Exponentiation**: Power operator (`^`)
- **Parentheses**: Full support for nested parentheses
- **Order of Operations**: Follows proper mathematical precedence
  - Exponentiation first (`^`)
  - Multiplication and division (`*`, `/`)
  - Addition and subtraction (`+`, `-`)
- **Debug Mode**: Optional verbose output for troubleshooting
- **User-friendly Interface**: Clear formatting with helpful prompts and error messages

## Installation

### Prerequisites

- C++ compiler with C++23 support (g++ recommended)
- Windows OS (build.bat is provided for Windows)

### Build Instructions

1. Clone or download the repository
2. Navigate to the project directory
3. Run the build script:

```bash
build.bat
```

Alternatively, compile manually:

```bash
g++ -o build/Kalkulate.exe main.cpp -lstdc++exp -std=c++23
```

## Usage

### Basic Usage

1. Run the executable:
```bash
./build/Kalkulate.exe
```

2. Enter your mathematical expression when prompted
3. Press Enter to see the result

### Example Expressions

```
(2^4)           → 16
3*(2+5)^2       → 147
10/2+3*4        → 17
(2+3)*(4-1)     → 15
2^3^2           → 512
```

### Debug Mode

Enable debug mode to see detailed calculation steps:

```bash
./build/Kalkulate.exe --debug
```

This will show:
- Parsed numbers and operators
- Step-by-step execution of operations
- Parentheses processing
- Intermediate results

## Program Structure

- **`evaluateExpression()`**: Handles parentheses evaluation
- **`evaluateSimple()`**: Evaluates expressions without parentheses
- **`calculateAnswer()`**: Performs individual arithmetic operations

## Error Handling

The calculator includes robust error handling for:
- Division by zero
- Mismatched parentheses
- Empty expressions
- Unknown operators
- Invalid input formats

## Author

- **cha0s66** - [GitHub](https://github.com/cha0s66)

## License

This project is licensed under the MIT License - see below for details:

```
MIT License

Copyright (c) 2026 cha0s66

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```

## Contributing

Contributions are welcome! Feel free to:
- Report bugs
- Suggest new features
- Submit pull requests

## Version

**Kalkulate V2** - Enhanced version with improved error handling, debug mode, and proper order of operations.