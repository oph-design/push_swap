<a name="readme-top"></a>




<h1 align="center">Push Swap</h1>
<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/oph-design/push_swap?color=lightblue" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/oph-design/push_swap?color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/oph-design/push_swap?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/created-at/oph-design/push_swap?color=green" />
</p>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#examples">Examples</a></li>
    <li><a href="#contact">Contact</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

<p align="center">
<img width="512" alt="Screen Shot 2024-03-21 at 3 06 09 PM" src="https://github.com/oph-design/push_swap/assets/115570424/067943be-873e-4942-afc8-8b77e8420c6b">
</p>


Push Swap is a program that can sort a stack A of numbers without duplicates, using only a second stack B and the following instructions.
  * `PUSH` pushes the number on top of one stack to the top of the stack
  * `SWAP` swaps the first 2 numbers in a stack
  * `ROTATE` puts the number on top of a stack on the bottom
  * `REVERSE ROTATE` puts the number on the bottom of a stack on the top

To sort the numbers the program uses a chunk sort algorithm. The numbers get indexed with their in-order-position. Based on the size of the stack
the numbers get assigend to chunks (chunk 1-20, 21-40, 41-60, etc.). The alogrithm goes through the through the stack A and finds all numbers from a chunk, roates them to the top and pushes them to stack B. After all the numbers are on stack B, the numbers are found by their index from highest to lowest and get pushed in order back to stack A. The result of the program is a string of instructions that were needed to sort the stack.


<!-- GETTING STARTED -->
## Getting Started

The following contains a description of how to use the program. It is recommend to run in an unix (linux or mac) environment.
As installing make and compilers in windows can be quite tedious. You can find a tutorial and setting up an ubuntu virtual machine <a href="https://www.linkedin.com/pulse/how-install-ubuntu-virtualbox-md-emamul-mursalin/">here</a>

### Prerequisites

You need to have make and gcc installed. For mac you need also xcode to perform the installation.
* linux (Debian based)
  ```sh
  sudo apt install build-essential
  ```
* MAC-OS
  ```sh
  xcode-select --install
  ```

### Installation

1. Clone the repo
   ```sh
   git clone https://github.com/oph-design/push_swap.git
   ```
2. Build the executabel at the root of the repository
   ```sh
   make push_swap
   ```
4. Create alias for your shell, for easier usage
   ```sh
   echo "alias pushswap=\"path-to-executable\"" >> $HOME/.zshrc
   ```



<!-- USAGE EXAMPLES -->
## Usage

The program is started, by running the executable with the stack as input.
   ```sh
   ./push_swap 5 7 1 4 8
   ```
You can use your alias instead of ./push_swap to execute from any directory

On succesful execution you can see the string of operation it took to sort the stack
 ```sh
  rra
  rra
  rra
  pb
  pb
  sa
  sa
  ra
  pa
  pa
   ```



<!-- EXMAPLES -->
## Examples

For a better experience I recommend to check out the <a href="https://pypi.org/project/push-swap-gui/">push-swap-gui</a> from elijahkash.</br>
This program can generate test stacks and visualizes the stack progression. (!You need to have python installed for this!)
<p></p>
<img width="558" alt="Screen Shot 2024-03-21 at 3 20 37 PM" src="https://github.com/oph-design/push_swap/assets/115570424/1d8ee835-2195-439e-88ea-2e082117094d">


<!-- CONTACT -->
## Contact

Ole-Paul Heinzelmann</br>
ole.paul.heinzelmann@protonmail.com </br>
<p></p>
<a href="https://www.linkedin.com/in/ole-paul-heinzelmann-a08304258/">
<img alt="linkedin shield" src="https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555" />
</a></br> 

<p align="right">(<a href="#readme-top">back to top</a>)</p>
