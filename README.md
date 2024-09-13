# retrieve-extractors

This project is TODO.

## Requirements

- C compiler (e.g., GCC)
- Python 3.x
- MuPDF library
- Meson build system
- Pipx for Python dependencies

## Installation

1. **Clone the repository:**

    ```sh
      git clone https://github.com/redte-ch/retrieve-extractors.git
      cd retrieve-extractors
    ```

2. **Install MuPDF:**

    ```sh
      brew install mupdf
    ```

3. **Install dependencies:**

    ```sh
      brew install meson pipx
      pipx install poe
      poe install
    ```

4. **Build the project:**

    ```sh
      poe build
    ```

5. **Test the project:**

    ```sh
      poe test
    ```
