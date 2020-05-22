class Node {
  public:
    Node() {
      north_ok = true;
      south_ok = true;
      east_ok = true;
      west_ok = true;
      has_had_flit = false;
    }

    void faulty(char d) {
      switch (d) {
        case 0: north_ok = false; break;
        case 1: east_ok = false; break;
        case 2: south_ok = false; break;
        case 3: west_ok = false; break;
        default: break;
      }
    }

    void has_flit() {
      has_had_flit = true;
    }

    bool north_ok;
    bool south_ok;
    bool east_ok;
    bool west_ok;
    bool has_had_flit;
};