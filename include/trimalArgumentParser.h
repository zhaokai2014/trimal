//
// Created by bioinfo on 8/06/17.
//

#ifndef TRIMAL_TRIMALARGUMENTPARSER_H
#define TRIMAL_TRIMALARGUMENTPARSER_H

#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>
#include "newAlignment.h"

using namespace std;

class trimalArgumentParser {

    bool appearErrors = false,
            complementary = false, colnumbering = false,
            nogaps = false, noallgaps = false,
            gappyout = false, strict = false,
            strictplus = false, automated1 = false,
            sgc = false, sgt = false, scc = false, sct = false,
            sfc = false, sft = false, sident = false, selectSeqs = false,
            selectCols = false, shortNames = false, splitbystop = false,
            terminal = false, keepSeqs = false,
            keepHeader = false, ignorestop = false;

    float conserve = -1,
            gapThreshold = -1,
            simThreshold = -1,
            comThreshold = -1,
            resOverlap = -1,
            seqOverlap = -1,
            maxIdentity = -1;
    int outformat = -1,
            prevType = -1,
            compareset = -1,
            stats = 0,
            windowSize = -1, gapWindow = -1, simWindow = -1,
            conWindow = -1, blockSize = -1, clusters = -1;

    /* Others variables */
    ifstream compare;
    float *compareVect = NULL;
    newAlignment  **compAlig  = NULL;
    string nline, *seqNames = NULL;
    sequencesMatrix *seqMatrix = NULL;
    similarityMatrix *similMatrix = NULL;
    newAlignment  *origAlig = NULL, *singleAlig = NULL, *backtranslation = NULL;

    int i = 1, lng, num = 0, maxAminos = 0, numfiles = 0, referFile = 0, *delColumns = NULL, *delSequences = NULL, *seqLengths = NULL;
    char c, *forceFile = NULL, *infile = NULL, *backtransFile = NULL, *outfile = NULL, *outhtml = NULL, *matrix = NULL,
            **filesToCompare = NULL, line[256];

public:
    void parseArguments(int argc, char *argv[]);
//    void applyArguments();

    bool info_arguments(int* argc, char* argv[], int* i);
    bool in_argument(int* argc, char* argv[], int* i);
    bool out_argument(int* argc, char* argv[], int* i);
    bool html_out_argument(int* argc, char* argv[], int* i);
    bool out_format_arguments(int* argc, char* argv[], int* i);
    bool matrix_argument(int* argc, char* argv[], int* i);
    bool compareset_argument(int* argc, char* argv[], int* i);
    bool force_select_argument(int* argc, char* argv[], int* i);
    bool back_trans_argument(int* argc, char* argv[], int* i);
    bool gap_threshold_argument(int* argc, char* argv[], int* i);
    bool sim_threshold_argument(int* argc, char* argv[], int* i);
    bool cont_threshold_argument(int* argc, char* argv[], int* i);
    bool cons_argument(int* argc, char* argv[], int* i);
    bool select_cols_argument(int* argc, char* argv[], int* i);
    bool no_gaps_argument(int* argc, char* argv[], int* i);
    bool no_all_gaps_argument(int* argc, char* argv[], int* i);
    bool keep_seqs_argument(int* argc, char* argv[], int* i);
    bool keep_header_argument(int* argc, char* argv[], int* i);
    bool gappy_out_argument(int* argc, char* argv[], int* i);
    bool strict_argument(int* argc, char* argv[], int* i);
    bool strict_plus_argument(int* argc, char* argv[], int* i);
    bool automated1_argument(int* argc, char* argv[], int* i);
    bool col_overlap_argument(int* argc, char* argv[], int* i);
    bool seq_overlap_argument(int* argc, char* argv[], int* i);
    bool seqs_select_argument(int* argc, char* argv[], int* i);
    bool max_identity_argument(int* argc, char* argv[], int* i);
    bool clusters_argument(int* argc, char* argv[], int* i);
    bool terminal_only_argument(int* argc, char* argv[], int* i);
    bool window_argument(int* argc, char* argv[], int* i);
    bool gap_window_argument(int* argc, char* argv[], int* i);
    bool sim_window_argument(int* argc, char* argv[], int* i);
    bool con_window_argument(int* argc, char* argv[], int* i);
    bool block_argument(int* argc, char* argv[], int* i);
    bool stats_arguments(int* argc, char* argv[], int* i);
    bool complementary_argument(int* argc, char* argv[], int* i);
    bool col_numbering_argument(int* argc, char* argv[], int* i);
    bool split_by_stop_codon_argument(int* argc, char* argv[], int* i);
    bool ignore_stop_codon_argument(int* argc, char* argv[], int* i);

    //todo PostProcessing;


};


#endif //TRIMAL_TRIMALARGUMENTPARSER_H
