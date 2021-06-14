# CryXor

## Description

CryXor is an XOR encryption software. It allows you to encrypt a file with a password (Symmetric encryption).

## Installation

Clone the repository : `git clone https://github.com/Ectario/CryXor.git`

## Usage

- Open a terminal 
- Go to the CryXor.exe folder
- To Encrypt/Decrypt file :

  * **Encrypt** File "exampleFile.extension" with using absolute or relative path : `CryXor.exe encrypt [path]/exampleFile.extension [password]` (the password must be between quotes to avoid special character problems) 

    _Hint : You can just write `CryXor.exe encrypt exampleFile.extension [password]`  if the file is in the same directory than CryXor.exe_
    
   * **Decrypt** File "exampleFile.extension.CryXor" with using absolute or relative path : `CryXor.exe decrypt [path]/exampleFile.extension.CryXor [password]` (the password must be between quotes to avoid certain problems) 

       _Hint : You can just write `CryXor.exe decrypt exampleFile.extension.CryXor [password]`  if the file is in the same directory than CryXor.exe_
    
**Warning** : When decrypting the file, if the user enters **a wrong password** and has opened the terminal in **administrator mode**, then the encrypted file will disappear leaving only the badly decrypted one. The **data** will then be **lost**.

## Method used

Each piece of information is coded by 0s or 1s in a computer, including files and CryXor use this point. 

What CryXor does for a file which (suppose) is encoded by 011001:

### Encryption

 - First of all we recover the password. 
 - The entered password is a String, we then convert it to binary. Suppose here 101 (Normally a String is encoded on byte or 8 bits, but to simplify the example 3 bits will suffice). 
 - The CryXor algorithm will then do an exclusive or (XOR) between 101 (password) and 011001 (file). 

![encryption](https://user-images.githubusercontent.com/61197119/121943747-2f545380-cd52-11eb-915e-e13bda1a431b.png)

- Which gives us 110100. It will therefore be the binary information of the file which is now encrypted.

### Decryption

It is a symmetric encryption which works the same way during encryption as during decryption, so the steps are the same.

![decryption](https://user-images.githubusercontent.com/61197119/121944307-d0dba500-cd52-11eb-85c9-f9a640f58342.png)
