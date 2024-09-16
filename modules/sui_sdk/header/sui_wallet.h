#ifndef SUI_WALLET_H
#define SUI_WALLET_H

#include <inttypes.h>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <string>

extern "C" {
struct Wallet {
	std::string address;
	std::string mnemonic;
	std::string public_base64_key;
	std::string private_key;
	std::string key_scheme;
};

struct WalletList {
	Wallet *wallets;
	size_t length;
};
// Wallet
class SuiWallet {
public:
	static WalletList get_wallets();
	static void free_wallet_list(WalletList wallet_list);
	static Wallet *generate_wallet(const char *key_scheme, const char *word_length);
	static Wallet *generate_and_add_key();
	static Wallet *get_wallet_from_address(const char *address);
	static void free_wallet(Wallet *wallet);
	static void import_from_private_key(const char *key_base64);
	static char *import_from_mnemonic(const char *mnemonic);
};
}

#endif // SUI_WALLET_H
