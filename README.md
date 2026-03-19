# HFT Order Matching Engine Simulator
A high-performance Limit Order Book (LOB) simulator built in C++ for High-Frequency Trading (HFT) backtesting. This engine implements the **Price-Time Priority (FIFO)** matching algorithm, achieving sub-microsecond latency.
##Performance Metrics
- **Average Latency: ~1299 ns per order (Tested on Arch Linux)
- **Throughput:Capable of processing 10,000+ orders in milliseconds.
- **Stress Test: Verified using synthetic data generated via Python.
##Features
- **Price-Time Priority: Orders are matched based on the best price and then the time of arrival.
- **Limit Orders: Supports Buy (B) and Sell (S) limit orders.
- **Fast Execution: Optimized using STL containers and efficient C++ memory management.
- **Scalable:** Includes a Python-based data generator to simulate real-market loads.
##Project Structure
- `src/`: Core engine logic and order book implementation.
- `include/`: Header files for modular design.
- `data/`: Contains `gen.py` (Python stress-tester) and `orders.csv`.
- `build/`: CMake build artifacts.
##How to Build & Run
1. Clone the repository:**
   ```bash





   
