/*
Language: ADL
Description: A Particle Physics Analysis Description Language
Highlight.js repository: https://github.com/unelg/CutLang/tree/master/scripts/highlightjs-adl
Runtime interpreter repository: https://github.com/unelg/CutLang
*/

export default function(hljs) {

  var KEYWORDS_KEYWORD = `
    def define
    cmd cut select command
    reject
    obj object
    algo region algorithm
    TRGe
    TRGm

    info
    experiment
    id
    title
    publication
    sqrtS
    lumi
    arXiv
    hepdata
    doi

    counts
    countsformat
    stat
    syst
    process
    
    systematic
  `

  var KEYWORDS_BUILT_IN = `
    union
    alias
    btag
    ctag
    tautag
    pdgid
    ptcone
    etcone
    status
    vertext
    vertexx
    vertexy
    vertexz
    vertextr
    btagdeepb
    msoftdrop
    daughters constituents
    tau1
    tau2
    tau3
    fmegajets
    fhemisphere
    fmr
    fmtr
    fmt2
    fmtautau
    minipfrelisoall
    relisoall
    pfrelIso03all
    dxy d0
    dz
    dmvanewdm2017v2
    softid
    applyhm
    iddecaymode
    idisotight
    idantieletight
    idantimutight
    tightid
    puid
    genpartidx
    decaymode
    HLT_IsoMu17_eta2p1_LooseIsoPFTau20
    sieie
    
    phi
    eta
    rap
    abseta
    pt
    pz
    dr
    dphi
    deta
    size count numof
    nbf
    fht
    metmwt
    mwt
    met
    all
    lepsf
    btagsf
    xslumicorrsf
  `

  var KEYWORDS_TYPE = `
      
  `

  var KEYWORDS_OPERATOR = `
    EQ
    ne
    LE
    GE
    lt
    gt
    and
    or
    not
  `

  var KEYWORDS_SYMBOL = `
      
  `

  var KEYWORDS_LITERAL = `
    ontrue
    offfalse
    nvars
    errors
    tabletype
    takeusing
    histo
    weight
    table
    skiphistos
    skipeffs
    gen
    ele electron
    muo muon
    tau
    pho photon
    jet
    fjet fatjet
    qgjet
    bin
    numet
    metlv
    lep
    hlt
    bjet
  `

  var KEYWORDS_RELEVANCE_ONLY = `
    __one
    __two
    __three
    __four
  `

  var KEYWORDS = {
    keyword: KEYWORDS_KEYWORD,
    built_in: KEYWORDS_BUILT_IN,
    type: KEYWORDS_TYPE,
    literal: KEYWORDS_LITERAL,
    //number: KEYWORDS_NUMBER,
    operator: KEYWORDS_OPERATOR,
    //punctuation: KEYWORDS_PUNCTUATION,
    //property: KEYWORDS_PROPERTY,
    //regexp: KEYWORDS_REGEXP,
    //string: KEYWORDS_STRING,
    symbol: KEYWORDS_SYMBOL,
    //variable: KEYWORDS_VARIABLE,
    _relevance_only: KEYWORDS_RELEVANCE_ONLY
  }

  var separators = [' ', '\t', '\n']
  var process = [KEYWORDS]
  for(var a=0;a<process.length;a++){
    for(const [key, value] of Object.entries(process[a])){
      process[a][key]=value.split(new RegExp(separators.join('|'), 'g'))
    }
    for(const [key, value] of Object.entries(process[a])){
      for(var i=0;i<value.length;i++){
        if(process[a][key][i]=="" || !process[a][key][i]){
          delete process[a][key][i]
        }
      }
    }
  }

  console.log(KEYWORDS)
  
  return {
    case_insensitive: true, // language is case-insensitive
    keywords: KEYWORDS,
    contains: [
      {
        scope: 'string',
        begin: '"',
        end: '"'
      },
      {
        scope: 'operator',
        begin: /==|!=|~!|~=|<=|>=|<|>|\[\]|\]\[|&&|\|\|/
      },
      hljs.COMMENT(
        '#', // begin
        '\\n' // end
      )
    ]
  };
}