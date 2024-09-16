import qiskit as qk

q = qk.QuantumRegister(2) # Initiating 2 qubits
c = qk.ClassicalRegister(2) # Initiating 2 classical bits
circuit = qk.QuantumCircuit(q,c) # Preparing the Quantum Circuit
circuit.h(q[0]) # Adding a Hadamard Gate to Qubit 0 to superpose with Qubit 1
circuit.cx(q[0] , q[1]) # CNOT gate added as esplained: Qubit 0 and Qubit 1 connected
circuit.measure(q , c) # Measuring
print(circuit)

simulator = qk.BasicAer.get_backend('qasm_simulator') # Using a Quantum Simulator on Local Machine for simulation
job = qk.execute(circuit , simulator)
output = job.result()

counts = output.get_counts(circuit) # get_counts returns the binary outcome
print(counts)
