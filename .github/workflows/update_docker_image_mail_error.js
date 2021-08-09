#! /usr/bin/env node

var sgMail = require('@sendgrid/mail');
sgMail.setApiKey(process.env.SENDGRID_API_KEY);

var fs = require('fs')

var _version = fs.readFileSync('./VERSION');

var msg = {
    to: ['gokhan.unel@gmail.com','ssekmen@gmail.com','tobuba2@gmail.com'],
    from: 'gokhan.unel@cern.ch',
    subject: 'CutLang Package Report - Docker, Error v' + _version,
    text: 'When uploading new conda package, errors found. New conda package '+_version+' IS NOT AVAILABLE',
};

sgMail
    .send(msg)
    .then(() => console.log('Mail sent successfully'))
    .catch(error => console.error(error.toString()));
