# 📇 Address Book in C

A simple Address Book Management System built in C.  
It allows users to add, search, edit, delete, list, and save contacts with input validation.

---

## ✨ Features

- ➕ Add Contact – Create a new contact with name, phone, and email  
- 🔍 Search Contact – Find contacts by name, phone, or email  
- ✏️ Edit Contact – Update existing contact details  
- ❌ Delete Contact – Remove contact by index, phone, or email  
- 📜 List Contacts – Display all stored contacts  
- 💾 Save Contacts – Save contacts to `Addressbookcontacts.csv`  
- 📂 Load Contacts – Automatically loads saved contacts at startup  
- 🖥️ User Interface – Simple and readable command-line interface  

---

## 🛡️ Input Validation

- **Name**
  - Only alphabets and spaces  
  - Cannot be empty  
  - No leading spaces  

- **Phone**
  - Exactly 10 digits  
  - Only numbers allowed  
  - No duplicate numbers  

- **Email**
  - Must end with valid domain (default: `@gmail.com`)  
  - Allows letters, numbers, `_` and `.`  
  - No duplicate emails  

---

## 📂 Project Structure
<pre> ```text ├── main.c # Entry point, menu handling ├── contacts.c # Core features ├── contacts.h # Function declarations & struct ├── validation.c # Validation logic ├── validation.h # Validation headers ├── Addressbookcontacts.csv # Stored data file ``` </pre>
