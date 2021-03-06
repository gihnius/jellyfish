#include <ruby.h>

#include "jellyfish.h"

VALUE jellyfish = Qnil;

void Init_cjellyfish();

VALUE method_jaro_winkler(VALUE, VALUE, VALUE, VALUE);
VALUE method_jaro_distance(VALUE, VALUE, VALUE);
VALUE method_hamming_distance(VALUE, VALUE, VALUE);
VALUE method_levenshtein_distance(VALUE, VALUE, VALUE);
VALUE method_damerau_levenshtein_distance(VALUE, VALUE, VALUE, VALUE, VALUE);
VALUE method_soundex(VALUE, VALUE);
VALUE method_metaphone(VALUE, VALUE);
VALUE method_nysiis(VALUE, VALUE);
VALUE method_match_rating_codex(VALUE, VALUE);
VALUE method_match_rating_comparison(VALUE, VALUE, VALUE);

VALUE method_stem(VALUE, VALUE);

void Init_cjellyfish() {
    jellyfish = rb_define_module("JellyFish");
    rb_define_method(jellyfish, "jaro_winkler", method_jaro_winkler, 3);
    rb_define_method(jellyfish, "jaro_distance", method_jaro_distance, 2);
    rb_define_method(jellyfish, "hamming_distance", method_hamming_distance, 2);
    rb_define_method(jellyfish, "levenshtein_distance", method_levenshtein_distance, 2);
    rb_define_method(jellyfish, "damerau_levenshtein_distance", method_damerau_levenshtein_distance, 4);
    rb_define_method(jellyfish, "soundex", method_soundex, 1);
    rb_define_method(jellyfish, "metaphone", method_metaphone, 1);
    rb_define_method(jellyfish, "nysiis", method_nysiis, 1);
    rb_define_method(jellyfish, "match_rating_codex", method_match_rating_codex, 1);
    rb_define_method(jellyfish, "match_rating_comparison", method_match_rating_comparison, 2);

    VALUE jf_stemmer = rb_define_class_under(jellyfish, "Stemmer", rb_cObject);
    rb_define_method(jf_stemmer, "stem", method_stem, 1);
}

VALUE method_jaro_winkler(VALUE self, VALUE str1, VALUE str2, VALUE long_tolerance) {
    double d = jaro_winkler(RSTRING_PTR(str1), RSTRING_PTR(str2), long_tolerance);
    return rb_float_new(d);
}

VALUE method_jaro_distance(VALUE self, VALUE str1, VALUE str2) {
    double d = jaro_distance(RSTRING_PTR(str1), RSTRING_PTR(str2));
    return rb_float_new(d);
}

VALUE method_hamming_distance(VALUE self, VALUE str1, VALUE str2) {
    return hamming_distance(RSTRING_PTR(str1), RSTRING_PTR(str2));
}

VALUE method_levenshtein_distance(VALUE self, VALUE str1, VALUE str2) {
    return levenshtein_distance(RSTRING_PTR(str1), RSTRING_PTR(str2));
}

VALUE method_damerau_levenshtein_distance(VALUE self, VALUE str1, VALUE str2, VALUE len1, VALUE len2) {
    return damerau_levenshtein_distance(RSTRING_PTR(str1), RSTRING_PTR(str2), NUM2UINT(len1), NUM2UINT(len2));
}

VALUE method_soundex(VALUE self, VALUE str) {
    return rb_str_new2(soundex(RSTRING_PTR(str)));
}

VALUE method_metaphone(VALUE self, VALUE str) {
    return rb_str_new2(metaphone(RSTRING_PTR(str)));
}

VALUE method_nysiis(VALUE self, VALUE str) {
    return rb_str_new2(nysiis(RSTRING_PTR(str)));
}

VALUE method_match_rating_codex(VALUE self, VALUE str) {
    return rb_str_new2(match_rating_codex(RSTRING_PTR(str)));
}

VALUE method_match_rating_comparison(VALUE self, VALUE str1, VALUE str2) {
    return match_rating_comparison(RSTRING_PTR(str1), RSTRING_PTR(str2));
}

/* copied from porter.c */
struct stemmer {
	char * b;       /* buffer for word to be stemmed */
	int k;          /* offset to the end of the string */
	int j;          /* a general offset into the string */
};

// stemmer instance method
VALUE method_stem(VALUE self, VALUE b) {
	size_t length, i;
	char *word;
	struct stemmer z;
	VALUE str, rv;

	str = StringValue(b);
	word = malloc(RSTRING_LEN(str) + 1);
	strncpy(word, RSTRING_PTR(str), RSTRING_LEN(str));
	word[RSTRING_LEN(str)] = '\0';

	length  = stem(&z, word, strlen(word)-1);
	word[length+1] = 0;
	rv = rb_str_new2(word);
	free(word);

	return rv;
}
