// Mo's Algorithm
const ll BLOCK_SIZE = 500; // sqrt(n) or some near value

// TODO: Data structures for Mo's algo

// TODO: remove value at idx from data structure
void remove(ll idx){

};

// TODO: add value at idx from data structure
void add(ll idx){

};

// TODO: extract the current answer of the data structure
ll get_answer(){

}; 

// l, r -> 0 based indexing
struct Query { 
    ll l, r, idx;
    bool operator<(Query other) const
    {
        return make_pair(l / BLOCK_SIZE, r) <
               make_pair(other.l / BLOCK_SIZE, other.r);
    }
};

vector<ll> mo_s_algorithm(vector<Query> queries) {
    vector<ll> answers(queries.size());
    sort(queries.begin(), queries.end());

    // TODO: initialize data structure

    ll cur_l = 0;
    ll cur_r = -1;
    // invariant: data structure will always reflect the range [cur_l, cur_r]
    for (Query q : queries) {
        while (cur_l > q.l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.l) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > q.r) {
            remove(cur_r);
            cur_r--;
        }
        answers[q.idx] = get_answer();
    }
    return answers;
}
