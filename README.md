# Realtek RTL8851BU USB Wi-Fi Driver (Linux)

This is an out-of-tree Linux kernel driver for the **Realtek RTL8851BU** USB Wi-Fi adapter.  
The code was originally provided by [UGREEN Support] and has been patched and maintained here to build cleanly on modern Linux kernels (6.x and newer).

Tested against CM845 UGreen WiFi6/BT5.4 USB adapter AX900 

---

## ✨ Features

- Supports RTL8851BU chipset (802.11ax / Wi-Fi 6 USB adapters e.g. Ugreen AX900 Wi-Fi6 Bluetooth5.4 USB adapter model CM845)
- Builds against Linux kernel **6.x** (tested up to 6.14 / 6.15)
- Includes fixes for:
  - Missing headers (`drv_types.h` and friends)
  - `cfg80211` API changes (`get_tx_power`, `set_monitor_channel`, `cac_event`, etc.)
  - Warnings promoted to errors on new GCC
  - Noisy debug output (configurable via module parameters)

---

## 📦 Installation

### 1. Clone this repository
```bash
git clone https://github.com/leopck/rtl8851bu.git
cd rtl8851bu
```

### 2. Build and install

```bash
make
sudo make install
```

### 3. Load the module

```bash
sudo modprobe cfg80211
sudo modprobe 8851bu
```
