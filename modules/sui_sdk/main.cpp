#include "./header/sui_lib.h"
#include <stdio.h>
void print_wallet(const Wallet *wallet) {
	printf("Wallet Address: %s\n", wallet->address ? wallet->address : "Not set");
	printf("Mnemonic: %s\n", wallet->mnemonic ? wallet->mnemonic : "Not set");
	printf("Public Base64 Key: %s\n", wallet->public_base64_key ? wallet->public_base64_key : "Not set");
	printf("Private Key: %s\n", wallet->private_key ? wallet->private_key : "Not set");
	printf("Key Scheme: %s\n", wallet->key_scheme ? wallet->key_scheme : "Not set");
	printf("\n");
}
void test_get_wallets() {
	// Retrieve the list of wallets
	SuiWallet suiWallet;
	WalletList wallet_list = SuiWallet::get_wallets();

	// Check if the retrieval was successful
	if (wallet_list.wallets == NULL) {
		printf("Error retrieving wallets\n");
	}
	printf("Error retrieving wallets\n %s", wallet_list);
	// Iterate over the wallets and print their details
	// for (size_t i = 0; i < wallet_list.length; i++)
	// {
	//     print_wallet(&wallet_list.wallets[i]);
	// }
}

int main() {
	test_get_wallets();
}