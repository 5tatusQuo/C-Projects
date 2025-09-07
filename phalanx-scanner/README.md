# Phalanx YARA Scanner

A lightweight YARA-based malware scanner written in C for Linux and Windows systems. This project is purely for learning C.

## Project Phases

### Phase 1: Core Scanner
- [ ] YARA library integration
- [ ] File hashing (MD5/SHA256)
- [ ] Basic YARA rule matching
- [ ] File type detection (PE, ELF)

### Phase 2: Detection Engine
- [ ] YARA rule compilation and optimization
- [ ] Threat classification system
- [ ] File filtering for executables
- [ ] Detection confidence scoring

### Phase 3: User Interface
- [ ] Command-line argument parsing
- [ ] Scan options and output modes
- [ ] Interactive threat response
- [ ] Quarantine system

### Phase 4: Real-time Protection
- [ ] File system monitoring (inotify)
- [ ] Background service/daemon
- [ ] Real-time scanning
- [ ] System integration

### Phase 5: Advanced Features
- [ ] YARA rule updates
- [ ] Multi-threading
- [ ] Performance optimization
- [ ] Cross-platform support

## Usage

```bash
make
./phalanx /path/to/scan
```