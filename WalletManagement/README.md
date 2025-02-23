# Flipkart Wallet - Requirements

## 1. User Registration
- Users need to register on Flipkart to use this wallet.

## 2. Loading Money into Wallet
- The user can load money into their wallet via various sources (Credit Card, Debit Card, UPI, etc.).
- **Minimum amount** of load money should be **greater than 0**.
- **Assumption**: No need for integration from sources; can be implemented with just a success acknowledgment.

## 3. Sending Money
- Users can send money to other users from their wallet.
- **Minimum transaction amount** must be **greater than 0**.
- The user must have a **sufficient balance** in their wallet before making a transaction.

## 4. Fetching Wallet Balance
- The user can check their wallet balance at any time.
- The balance should consider **both credit & debit transactions**.

## 5. Transaction History
### Sorting Transactions
Users can sort transaction history based on:
- **Amount** (`amount`)
- **Transaction DateTime** (`time`)

### Filtering Transactions
Users can filter transactions based on:
- **Send or Receive Amount** (`send/receive`)

### Assumption:
- Only **one filter and one sorting field** will be considered at a time.
