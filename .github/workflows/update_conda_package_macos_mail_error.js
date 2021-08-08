#! /usr/bin/env node

const sgMail = require('@sendgrid/mail');
sgMail.setApiKey(process.env.SENDGRID_API_KEY);

const fs = require('fs'),

const version = data = fs.readFileSync('./VERSION');

const msg = {
    to: ['tobuba2@gmail.com'],
    from: 'tobuba2@gmail.com',
    subject: 'CutLang Package Report - Conda, Macos, Error v'+ version,
    text: 'When uploading new conda package, errors found. New conda package '+version+' IS NOT AVAILABLE',
};

sgMail
    .send(msg)
    .then(() => console.log('Mail sent successfully'))
    .catch(error => console.error(error.toString()));
